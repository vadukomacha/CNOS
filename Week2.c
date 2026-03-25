#include <stdio.h>
#include<string.h>

int main() {
    char data[100],key[30],temp[130];
    int dataLen,keyLen,i,j;
    printf("Enter Data (bit string): ");
    scanf("%s",data);
    printf("Enter Key (bit string): ");
    scanf("%s",key);
    dataLen=strlen(data);
    keyLen=strlen(key);
    strcpy(temp,data);
    for(i=0;i<keyLen-1;i++)
    temp[dataLen+i]='0';
    temp[dataLen+keyLen-1]='\0';
    for(i=0;i<dataLen;i++){
        if(temp[i]=='1'){
            for(j=0;j<keyLen;j++){
                temp[i+j]=(temp[i+j]==key[j])?'0':'1';
            }
        }
    }
    printf("\nRemainder: ");
    for(i=dataLen;i<dataLen+keyLen-1;i++)
    printf("%c",temp[i]);
    printf("\nFinal Codeword (Data+Remainder): ");
    printf("%s",data);
    for(i=dataLen;i<dataLen+keyLen-1;i++)
    printf("%c",temp[i]);
    printf("\n");
    return 0;
}
