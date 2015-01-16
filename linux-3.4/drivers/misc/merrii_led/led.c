
/*****************************************************************************

 Date: 2013/01/23
 Revision: 1.0
 Author: hanbiao
 *****************************************************************************/

/*
 * This software program is licensed subject to the GNU General Public License
 * 

 * (C) Copyright 2013 Wits and AllWinner
 * All Rights Reserved
 */


/* file a80_humbvga.c
   brief This file contains all function implementations for the a80_humbvga in linux

*/

#include <linux/module.h>
#include <linux/init.h>

//include <mach/system.h>
#include <mach/hardware.h>
#include <mach/sys_config.h>
#include <linux/gpio.h>
#include <linux/regulator/consumer.h>



//hanbiao only for test.
#define A80_LED_DEBUG

#ifdef A80_LED_DEBUG
#define a80_led_dbg(x...)	printk(x)
#else
#define a80_led_dbg(x...)
#endif


/*************************************************************
 *
 *      register definitions
 *
 ************************************************************/
 
#define DRIVER_VERSION		"1.9"



static struct gpio_config enable_io ;

//hanbiao addd for gps
static struct gpio_config gps_io ;

/*
 * hanbiao GPIO control
 */
static void a80_led_gpio_write(struct gpio_config *gpio, int level)
{
	//	struct csi_dev *dev=(struct csi_dev *)dev_get_drvdata(sd->v4l2_dev->dev);
	  if(gpio->gpio==GPIO_INDEX_INVALID)
	  {
	    printk("invalid gpio\n");
	    return;
	  }
	  
	if(gpio->mul_sel==1)
	{
	  gpio_direction_output(gpio->gpio, level);
	  gpio->data=level;
	} else {
	  printk("gpio is not in output function\n");
	}
}

static int a80_led_fetch_sysconfig_para(void)
{
	int ret = -1;
	int device_used = -1;
	script_item_u	val;
	script_item_value_type_e  type;
    __u32 twi_addr = 0;
		
	a80_led_dbg("========%s===================\n", __func__);

	type = script_get_item("vga_para", "vga_used", &val);
 
	if (SCIRPT_ITEM_VALUE_TYPE_INT  != type) {
		pr_err("%s: type err  device_used = %d. \n", __func__, val.val);
		goto script_get_err;
	}
	device_used = val.val;
	
	if (1 == device_used) {

		
        /* fetch reset/power/standby/flash/af io issue */
		type = script_get_item("vga_para","vga_en", &val);
		if (SCIRPT_ITEM_VALUE_TYPE_PIO != type) {
		      pr_err("type err ch7026_en \n");
			goto script_get_err;
		} else {
		  enable_io.gpio=val.gpio.gpio;
		  enable_io.mul_sel=val.gpio.mul_sel;
		}

 //hanbiao add for gps start
 /* fetch reset/power/standby/flash/af io issue */
		type = script_get_item("vga_para","gps_en", &val);
		if (SCIRPT_ITEM_VALUE_TYPE_PIO != type) {
		      pr_err("type err gps_en \n");
			goto script_get_err;
		} else {
		  gps_io.gpio=val.gpio.gpio;
		  gps_io.mul_sel=val.gpio.mul_sel;
		}

//hanbiao add for gps end

		ret = 0;
		
	} else {
		pr_err("%s: a80_led_unused. \n",  __func__);
		ret = -1;
	}



script_get_err:
	a80_led_dbg("=========script_get_err============\n");
	return ret;
}




static int a80_led_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
    
	return 0;
}

static int a80_led_remove(struct i2c_client *client)
{


	return 0;
}




static int __init a80_led_init(void)
{
	int ret = 0;
	printk("======%s=========. \n", __func__);
	
	if(!a80_led_fetch_sysconfig_para())
	{
		a80_led_gpio_write(&enable_io, 1);	
		
		//hanbiao add for GPS
		a80_led_gpio_write(&gps_io, 1);	
		
		
		return ret;
	}
	else
	{
	       printk("======%s==ERROR ERROR=======. \n", __func__);
	       return -1;
	}

	//return ret;
}

static void __exit a80_led_exit(void)
{
	//i2c_del_driver(&a80_led_driver);
}

MODULE_AUTHOR("bill <bill@wits-tech.com>");
MODULE_DESCRIPTION("a80_led driver");
MODULE_LICENSE("GPL");

module_init(a80_led_init);
module_exit(a80_led_exit);

