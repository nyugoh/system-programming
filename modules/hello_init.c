#include <linux/kernel.h>
#include <linux/module.h>

int hell_world_int(void){
  printk(KERN_ALERT, "Hello world, Joe");
  return 0;
}

void hell_world_exit(void) {
  printk(KERN_ALERT, "Bye world, Joe");
}

module_init(hell_world_int);
module_exit(hell_world_exit);