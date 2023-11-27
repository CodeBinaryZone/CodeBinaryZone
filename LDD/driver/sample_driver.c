#include <linux/module.h>
#include <linux/fs.h>

static int my_device_open(struct inode *inode, struct file *file)
{
    pr_info("Device opened\n");
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file)
{
    pr_info("Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = my_device_open,
    .release = my_device_release,
};

static int __init my_driver_init(void)
{
    register_chrdev( major, "my_device", &fops);
    pr_info("Simple Device Driver: Loaded\n");
    return 0;
}

static void __exit my_driver_exit(void)
{
    unregister_chrdev(major, "my_device");
    pr_info("Simple Device Driver: Unloaded\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux device driver");
MODULE_VERSION("1.0");

