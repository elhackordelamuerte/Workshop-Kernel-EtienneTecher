#include "hello.h"

MODULE_LICENSE("IDK");
MODULE_DESCRIPTION("My firt kernel module");
MODULE_AUTHOR("You");
static int n = 0;
static char *str = NULL;
module_init(my_init);
module_exit(my_exit);
module_param(n, int , S_IRUSR | S_IWUSR);
module_param(str , charp, S_IRUSR | S_IWUSR);

static int __init my_init(void)
{
    int i = 0;
    for(i = 0;i < n; i++){
        printk("Hello : %s", str);
    }
    return 0;
}

static void __exit my_exit(void)
{
    int i = 0;
    for(i = 0;i < n;i++){
        printk("Goodbye : %s\n", str);
    } 
}