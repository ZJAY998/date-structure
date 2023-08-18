#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <selinux/selinux.h>


// 判断系统语言函数
const char* getSystemLanguage() {
    char* lang = getenv("LANG");
    
    if (lang != NULL) {
        return lang;
    } else {
        return "未知"; // 若未找到系统语言设置，默认返回"未知"
    }
}

int main() {
    const char* systemLanguage = getSystemLanguage();
    printf("系统语言：%s\n", systemLanguage);

    
    int selinux_enabled = (0 <  is_selinux_enabled ());
    printf("%d\n",selinux_enabled);

    int num = security_getenforce();
    printf("%d\n",num);
    
    return 0;
}

