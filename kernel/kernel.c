#include <kernel/kernel.h>
#include <kernel/tty.h>
#include <kernel/process.h>
#include <kernel/handler.h>

#include <kernel/memory/memory.h>

#include <kernel/sys/syscall.h>
#include <kernel/sys/irq.h>

#include <fs/filesystem.h>
#include <drivers/display.h>

void kernel_main(void)
{
    init_display();

    print_tty("RaspberryPI OS\r\n");
    print_tty("by Luca Mienert\r\n");

    init_memory();
    init_fs();
    init_system_call();
    init_timer();
    init_interrupt_controller();
    init_process();
    enable_irq();
}
