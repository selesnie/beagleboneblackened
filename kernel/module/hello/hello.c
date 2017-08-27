#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jukka Selesniemi");
MODULE_DESCRIPTION("Sample kernel module");
MODULE_VERSION("0.1");

static char* message = "developer";
module_param(message, charp, S_IRUGO);
MODULE_PARM_DESC(message, "Message displayed in /var/log/kern.log");

static int __init hello_driver_init(void)
{
    printk(KERN_INFO "Hello, %s! Module loaded\n", message);

    return 0;
}

static void __exit hello_driver_exit(void)
{
    printk(KERN_INFO "Goodbye, %s! Module removed\n", message);
}

module_init(hello_driver_init);
module_exit(hello_driver_exit);
