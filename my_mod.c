#include <linux/module.h>	// required for module related stuff
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/kernel.h>
#include <asm/current.h>

int __init mojule_init(void){
  struct task_struct *head = current;
  struct list_head sibl = current->sibling;
  // struct task_struct *t;

  printk("Module insterted\n");

  list_for_each_entry(head, &sibl, sibling){
    printk("%s[%d]\n", head->comm, head->pid);
  }
  // list_for_each(p, head){ 

  // }

  return 0;
}
 
void __exit mojule_deinit(void){
  printk("Module removed \n");
}
 
module_init(mojule_init);
module_exit(mojule_deinit);
