#include "hello.h"

MODULE_LICENSE("IDK");
MODULE_DESCRIPTION("My firt kernel module");
MODULE_AUTHOR("You");

static int __init my_init(void)
{
    char *my_hello = "Hello kernel !\n"; 
    printk("%s\n", my_hello);
    return 0;
}

static void __exit my_exit(void)
{
    int i = 0;

    char *bye = "Goodbye kernel !\n";
    printk("%s\n", bye);

}
module_init(my_init);
module_exit(my_exit);