# Standard initialization
AC_PREREQ([2.69])
AC_INIT([aic8800_driver], [1.0], [support@example.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs
AC_PROG_CC
AC_PROG_MAKE_SET

# --- Custom Logic to find Linux Kernel Source ---
AC_ARG_WITH([kernel],
    [AS_HELP_STRING([--with-kernel=DIR], [location of the kernel source])],
    [KERNEL_DIR="$withval"],
    [KERNEL_DIR="/lib/modules/$(uname -r)/build"])

# Check if the directory exists
AS_IF([test ! -d "$KERNEL_DIR"], [
    AC_MSG_ERROR([Kernel directory $KERNEL_DIR not found. Use --with-kernel to specify it.])
])

# Export the variable so it can be used in Makefile.in
AC_SUBST([KERNEL_DIR])

# --- Check for specific Kernel Versions or Features if needed ---
# Example: Check for kernel 6.x features
AC_MSG_CHECKING([kernel version])
KVERSION=$(make -C $KERNEL_DIR kernelversion 2>/dev/null || echo "unknown")
AC_MSG_RESULT([$KVERSION])

# Final output
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
