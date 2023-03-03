#include "hello.h"

#pragma once

static struct file_operations fops = {
    .read = my_dev_read,
    .write = my_dev_write,
    .open = my_dev_open,
    .release = my_dev_close
};