#include "hello.h"
#include "struct.h"

MODULE_LICENSE("IDK");
MODULE_DESCRIPTION("My firt kernel module");
MODULE_AUTHOR("You");
static int n = 0;
static char *str = NULL;
static int is_open = 0;
module_init(my_init);
module_exit(my_exit);
module_param(n, int , S_IRUSR | S_IWUSR);
module_param(str , charp, S_IRUSR | S_IWUSR);

static int __init my_init(void)
{
    int response = register_chrdev(0, "coucou", &fops);
    printk("%d\n", response);
    return 0;
}

static void __exit my_exit(void)
{
    int i = 0;

    //char *bye = "Goodbye kernel !\n";
    for(i = 0;i < n;i++){
        printk("Goodbye : %s\n", str);

    } 
}

static int my_dev_open(struct inode *inode, struct file *file)
{
    if (is_open == 0){
        is_open = 1;
        printk("Device is open\n");
    }else {
        printk("Device is already open\n");
    }
    return 0;

}

static int my_dev_close(struct inode *inode, struct file *file)
{
    if (is_open == 1){
        is_open = 0;
        printk("Device is closed\n");
    } else {
       printk("Device is already closed\n");
    }
    return 0;
}

static ssize_t my_dev_read(struct file *file, char *buf, size_t len, loff_t *off)
{
    return 0;
}

static ssize_t my_dev_write(struct file *file, const char *buf, size_t len, loff_t *off)
{
    return 0;
}