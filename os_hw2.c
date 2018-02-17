#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>

#include <linux/pid_namespace.h>

int p_id;

/* 	
	A struct in the C programming language 
	(and many derivatives) is a composite data type (or record) 
	declaration that defines a physically grouped list of variables to 
	be placed under one name in a block of memory, allowing the different 
	variables to be accessed via a single pointer, or the struct declared name 
	which returns the same address.

*/

struct pid *pid_struct;
struct task_struct *task;
static struct proc_dir_entry *proc_write_entry;
char *proc_name="task_by_pid";

int read_proc(char *buf,char **start,off_t offset,int count,int *eof,void *data )
{
int len=0;
pid_struct = find_get_pid(p_id);
task = pid_task(pid_struct,PIDTYPE_PID);


/*sprintf stands for “String print”. 
Instead of printing on console, it store output on char buffer which are specified in sprintf
*/

len = sprintf(buf,"\nname %s\n ",task->comm);

return len;
}

int write_proc(struct file *file,const char *buf,int count,void *data )
{
int ret;
char *id;
id = (char *)kmalloc(1000*sizeof(char),GFP_KERNEL);
printk(KERN_INFO "buf passed %s",buf);
if(copy_from_user(id,buf,count))
    return -EFAULT;
printk(KERN_INFO "id passed %s",id);
p_id = simple_strtoul(id,NULL,0);
printk(KERN_INFO "pid %d ret %d",p_id,ret);
return sizeof(buf);
}

void create_new_proc_entry()
{
proc_write_entry = create_proc_entry(proc_name,0666,NULL);
if(!proc_write_entry)
      {
    printk(KERN_INFO "Error creating proc entry");
    return -ENOMEM;
    }
proc_write_entry->read_proc = read_proc ;
proc_write_entry->write_proc = write_proc;
printk(KERN_INFO "proc initialized");

}



int proc_init (void) {
    create_new_proc_entry();
    return 0;
}

void proc_cleanup(void) {
    printk(KERN_INFO " Inside cleanup_module\n");
    remove_proc_entry(proc_name,NULL);
}
MODULE_LICENSE("GPL");   
module_init(proc_init);
module_exit(proc_cleanup);

