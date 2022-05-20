#include <kernel/handler.h>
#include <asm/ports.h>

static uint64_t ticks = 0;

void init_interrupt_controller(void)
{
    out_word(DIST, 0);
    out_word(CPU_INTERFACE, 0);

    out_word(ICC_PR, 0xff);

    out_word(ICD_PR + 64, 0);
    out_word(ICD_PR + 38*4, 0);

    out_word(ICD_PTR + 64, 1);
    out_word(ICD_PTR + 38*4, 0x100);

    out_word(ICD_ICFGR + 16, 2);
    out_word(ICD_ICFGR + 36, 0x80000);
    
    out_word(ICD_ISENABLE + 8, 1);
    out_word(ICD_ISENABLE + 16, (1 << 25));

    out_word(DIST, 1);
    out_word(CPU_INTERFACE, 1);
}

void init_timer(void)
{
    out_word(TIMER_PREDIV, 0x7d);
    out_word(TIMER_LOAD, 19841);
    out_word(TIMER_CTL, 0b10100010);
}

static uint32_t get_irq_number(void)
{
    return in_word(ICC_ACK);
}

static void timer_interrupt_handler(void)
{
    uint32_t mask = in_word(TIMER_MSKIRQ);

    if (mask & 1) 
    {
        ticks++;
        wake_up(-1);
        out_word(TIMER_ACK, 1);
    }
}

uint64_t get_ticks(void)
{
    return ticks;
}

void handler(struct TrapFrame *tf)
{
    int schedule = 0;
    uint32_t irq;
    struct ProcessControl *process_control;

    switch (tf->trapno) 
    {
        case 1:
            if ((tf->spsr & 0xf) == 0) 
            {
                process_control = get_pc();
                printk("sync error occurs in process %d\r\n", (int64_t)process_control->current_process->pid);
                exit();
            }
            else 
            {
                printk("sync error at %x: %x\r\n", tf->elr, tf->esr);
                while (1) {}
            }
            break;

        case 2:
            irq = get_irq_number();

            if (irq == 64) 
            {
                timer_interrupt_handler();
                schedule = 1;
            }
            else if (irq == 96 + 57)
            {
                uart_handler();
            }
            else 
            {
                printk("unknown irq\r\n");
                while (1) {}
            }

            out_word(ICC_EOI, irq);
            break;

        case 3:
            system_call(tf);
            break; 

        default:
            printk("unknown exception\r\n");
            while (1) {}
    }

    if (schedule == 1)
        yield();
}