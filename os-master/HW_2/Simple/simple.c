#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SGG");
MODULE_DESCRIPTION("Simple Module");
int simple;
static int simple_init(void) {
printk(KERN_INFO "Loading Module\n");
return 0;
}
static void simple_exit(void) {
printk(KERN_INFO "Removing Module\n");

}


module_init(simple_init);
module_exit(simple_exit);

