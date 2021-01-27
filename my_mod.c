#include <linux/module.h>	// required for module related stuff
#include <linux/sched.h>
#include <asm/current.h>

int __init mojule_init(void){
  struct task_struct *head = current->parent;

  printk("Module insterted\n");
  printk("%s[%d]\n", head->comm, head->pid);

  return 0;
}
 
void __exit mojule_deinit(void){
  printk("Module removed \n");
}
 
module_init(mojule_init);
module_exit(mojule_deinit);
