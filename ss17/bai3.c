#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void inDaoNguoc(const char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void demSoTu(const char *str) {
    int count = 0, inWord = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    printf("So tu trong chuoi: %d\n", count);
}

void soSanhChuoi(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaChuCai(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Chuoi in hoa: %s\n", str);
}

void noiChuoi(char *str1, const char *str2) {
    strcat(str1, str2);
    printf("Chuoi sau khi noi: %s\n", str1);
}

int main() {
    char str1[1000] = {0};
    char str2[1000] = {0};
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh do dai\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va noi vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapChuoi(str1);
                break;

            case 2:
                inDaoNguoc(str1);
                break;

            case 3:
                demSoTu(str1);
                break;

            case 4:
                printf("Nhap vao chuoi moi: ");
                nhapChuoi(str2);
                soSanhChuoi(str1, str2);
                break;

            case 5:
                inHoaChuCai(str1);
                break;

            case 6:
                printf("Nhap vao chuoi moi: ");
                nhapChuoi(str2);
                noiChuoi(str1, str2);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (luaChon != 7);

    return 0;
}

