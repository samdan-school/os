#include <linux/module.h>   /* Needed by all modules  */
#include <linux/kernel.h>   /* Needed for KERN_INFO   */
#include <linux/init.h>     /* Needed for the macros  */
#include <linux/list.h>     /* Needed for linked list */
#include <linux/types.h>    /* Needed for list macros */
#include <linux/slab.h>     /* Needed for Kernel */

#define NUM_OF_BIRTHDAYS    6

/* Birthday struct  */
typedef struct _birthday {
    
    int day;
    int month;
    int year;
    struct list_head list;

} birthday ;

LIST_HEAD(birthday_list);
int birthdayList_init(void) {

    printk(KERN_INFO "Loading Module\n");
    birthday *person;
    int i = 0;
    for(i = 0; i < NUM_OF_BIRTHDAYS; i++) {
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = 2 + i;
        person->month = 7 + i;
        person->year = 1995 + i;
        INIT_LIST_HEAD(&person->list);
        list_add_tail(&person->list, &birthday_list);

    }
    birthday *ptr;
    list_for_each_entry(ptr, &birthday_list, list) {

        printk(KERN_INFO "Birthday: Month %d Day %d Year %d\n",
                ptr->month,
                ptr->day,
                ptr->year);
    }

           return 0;
}

void birthdayList_exit(void) {

    printk(KERN_INFO "Removing Module\n");
    birthday *ptr, *next;
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        list_del(&ptr->list);
        kfree(ptr);
    
    }

    printk(KERN_INFO "Memory free done\n");

}

module_init(birthdayList_init);
module_exit(birthdayList_exit);
