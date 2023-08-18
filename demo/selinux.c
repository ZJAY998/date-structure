#include <stdio.h>
#include <selinux/selinux.h>

int main() {
    // 检查是否启用 SELinux
    int enabled = is_selinux_enabled();
    if (enabled == 1) {
        printf("SELinux is enabled.\n");
    } else if (enabled == 0) {
        printf("SELinux is disabled.\n");
    } else {
        printf("Error checking SELinux status.\n");
    }

    // 获取当前 SELinux 强制模式
    int enforcing = security_getenforce();
    if (enforcing == 1) {
        printf("SELinux is in Enforcing mode.\n");
    } else if (enforcing == 0) {
        printf("SELinux is in Permissive mode.\n");
    } else {
        printf("Error checking SELinux enforcing mode.\n");
    }

    return 0;
}

