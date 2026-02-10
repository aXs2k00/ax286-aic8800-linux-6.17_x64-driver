#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

KSYMTAB_FUNC(get_fw_path, "", "");
KSYMTAB_FUNC(get_testmode, "", "");
KSYMTAB_FUNC(set_testmode, "", "");
KSYMTAB_FUNC(get_hardware_info, "", "");
KSYMTAB_FUNC(get_userconfig_xtal_cap, "", "");
KSYMTAB_FUNC(get_userconfig_txpwr_idx, "", "");
KSYMTAB_FUNC(get_userconfig_txpwr_ofst, "", "");
KSYMTAB_FUNC(aicwf_prealloc_txq_alloc, "", "");

SYMBOL_CRC(get_fw_path, 0x2986c864, "");
SYMBOL_CRC(get_testmode, 0x3a13f8bb, "");
SYMBOL_CRC(set_testmode, 0x81d11f06, "");
SYMBOL_CRC(get_hardware_info, 0xef93fea4, "");
SYMBOL_CRC(get_userconfig_xtal_cap, 0x12789d30, "");
SYMBOL_CRC(get_userconfig_txpwr_idx, 0x27e5f257, "");
SYMBOL_CRC(get_userconfig_txpwr_ofst, 0x377c82c7, "");
SYMBOL_CRC(aicwf_prealloc_txq_alloc, 0x6f8e754f, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x69acdf38, "memcpy" },
	{ 0x037a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xe2964344, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x15509ec7, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xdc50aae2, "__ref_stack_chk_guard" },
	{ 0x01000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x850714ff, "__tracepoint_sched_set_state_tp" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x962c8ae1, "usb_kill_anchored_urbs" },
	{ 0xa916b694, "strnlen" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x293a2f0c, "usb_submit_urb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x4ae0a9d2, "skb_pull" },
	{ 0x4a331da5, "vmalloc_noprof" },
	{ 0x4b031807, "kmem_cache_free" },
	{ 0x92b709e3, "const_current_task" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0x950eb34e, "__list_del_entry_valid_or_report" },
	{ 0xdb4defcd, "kthread_stop" },
	{ 0x7f5d41ff, "usb_deregister" },
	{ 0x2a59e6a5, "__fortify_panic" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xfb578fc5, "memset" },
	{ 0x9c328711, "kernel_read" },
	{ 0x940f44c1, "skb_dequeue_tail" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xc96561b3, "kmem_cache_alloc_noprof" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x51b621b4, "__netdev_alloc_skb" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xea80f2f9, "usb_unanchor_urb" },
	{ 0x43ea2ebc, "param_ops_string" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6dfbc83d, "skb_unlink" },
	{ 0x9f6ba1d3, "kthread_create_on_node" },
	{ 0x1e559ca3, "__preempt_count" },
	{ 0x999e8297, "vfree" },
	{ 0x3096be16, "names_cachep" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x726bc3c7, "wait_for_completion_killable_timeout" },
	{ 0xa94dc2e6, "filp_close" },
	{ 0xa8e75265, "__kmalloc_cache_noprof" },
	{ 0x6fd3ced0, "usb_kill_urb" },
	{ 0x03c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x0c3690fc, "_raw_spin_lock_bh" },
	{ 0xd0d08e42, "send_sig" },
	{ 0x754d539c, "strlen" },
	{ 0x953259fb, "dev_kfree_skb_any_reason" },
	{ 0x794d29e3, "param_ops_int" },
	{ 0xb5b54b34, "_raw_spin_unlock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe2c17b5d, "__SCT__might_resched" },
	{ 0x5b1327dd, "kmalloc_caches" },
	{ 0x53bbefe1, "__trace_set_current_state" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x4318c60a, "filp_open" },
	{ 0xd1b25d38, "usb_alloc_urb" },
	{ 0x43270de1, "usb_anchor_urb" },
	{ 0x7696f8c7, "__list_add_valid_or_report" },
	{ 0xf6e7d21e, "usb_free_urb" },
	{ 0x42d01fa0, "skb_put" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x6a5cc518, "__kmalloc_noprof" },
	{ 0xd3c09193, "consume_skb" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcdf39d50, "usb_register_driver" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x861d33fc, "module_layout" },
};

MODULE_INFO(depends, "usbcore");

MODULE_ALIAS("usb:vA69Cp8800d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:vA69Cp8801d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "E3110A3EB57BD17E0A1DAC3");
