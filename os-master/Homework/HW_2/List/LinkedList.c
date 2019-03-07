#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>

#define NUM_OF_BIRTHDAYS    6

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
        printk(KERN_INFO "Birthday: Month %d Day %d Year %d\n", ptr->month, ptr->day, ptr->year);
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
    printk(KERN_INFO "Removing birthday list and free momery!\n");
}

module_init(birthdayList_init);
module_exit(birthdayList_exit);