#include <linux/module.h>	// required for modules related stuffs
 
int __init mojule_init(void)
{
  printk("Module inserted \n");
  return 0;
}
 
void __exit mojule_deinit(void)
{
  printk("Module removed \n");
}
 
module_init(mojule_init);
module_exit(mojule_deinit);