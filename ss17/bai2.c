#include <stdio.h>

void nhapChuoi(char *str) {
    printf("Nhap vao chuoi: ");
    getchar(); // Xoa bo nho dem
    fgets(str, 1000, stdin);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

void inChuoi(const char *str) {
    printf("Chuoi vua nhap: %s\n", str);
}

void demChuCai(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            count++;
        }
    }
    printf("So luong chu cai trong chuoi: %d\n", count);
}

void demChuSo(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    }
    printf("So luong chu so trong chuoi: %d\n", count);
}

void demKyTuDacBiet(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == ' ')) {
            count++;
        }
    }
    printf("So luong ky tu dac biet trong chuoi: %d\n", count);
}

int main() {
    char str[1000] = {0};
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapChuoi(str);
                break;

            case 2:
                inChuoi(str);
                break;

            case 3:
                demChuCai(str);
                break;

            case 4:
                demChuSo(str);
                break;

            case 5:
                demKyTuDacBiet(str);
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (luaChon != 6);

    return 0;
}
