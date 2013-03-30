#include <linux/module.h>
#include <linux/kallsyms.h>

#define DRIVER_AUTHOR "Aaron Segaert (asegaert@gmail.com)"
#define DRIVER_DESCRIPTION "Defeat system write protect"
#define DRIVER_VERSION "1.0"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESCRIPTION);
MODULE_VERSION(DRIVER_VERSION);
MODULE_LICENSE("GPL");

int __init init_wp_mod(void)
{
	int *wp_new;
	ulong addr;

	printk(KERN_INFO "wp_mod: %s version %s\n", DRIVER_DESCRIPTION,
		DRIVER_VERSION);
	printk(KERN_INFO "wp_mod: by %s\n", DRIVER_AUTHOR);

	addr =  kallsyms_lookup_name("mmc0_write_prot_type");

	wp_new = (int*) addr;
	
	*wp_new = 0;
	
	printk("wp_mod installed, mmc0_write_prot_type=%d \n", *wp_new);

	return 0;
}

static void __exit exit_wp_mod(void)
{
}

module_init(init_wp_mod);
module_exit(exit_wp_mod);
