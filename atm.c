#include <stdio.h>
    int PIN =1111, norek =112233;
    long long saldo = 9000000000000;

void cekSaldo(){
    printf("Saldo anda : %lld", saldo);
}
   
void tarikTunai(){
    int nml;
    printf("Batas maksimal penarikan : Rp. 2.500.000 ");
    printf("Masukan nominal :");
    scanf("%d", &nml);
    getchar();
    if (nml <=2500000){                    
        printf("Anda telah menarik tunai sebesar %d", nml);
        saldo -= nml; nml=0;
        printf("\nSaldo anda sekarang %lld", saldo);
    }else{
        printf("Transfer gagal, nominal transfer melebihi batas maksimal");
    }
}

void transfer(){
    int tf,nml;
    printf("Masukan nomor rekening yang dituju :");
    scanf("%d", &tf);
    getchar();
    printf("Masukan nominal :");
    scanf("%d", &nml);
    getchar();
    if(norek == tf){
        printf("Transfer gagal, nomor rekening tujuan sama dengan rekening anda");
    } else if(nml <= saldo){
        saldo -= nml; nml=0;
        printf("Transfer berhasil, saldo anda sekarang %lld", saldo);
    } else{
        printf("Transfer gagal, saldo anda tidak cukup");
    }
}

void ubahPin(){
    int lamaPin, baruPin, ulangPin;
    printf("Ubah PIN anda\n");
    printf("Masukan PIN lama anda : ");
    scanf("%d", &lamaPin);
    getchar();
    if(lamaPin == PIN){
        do{
            printf("Masukan PIN baru anda : ");
            scanf("%d", &baruPin);
            getchar();
            printf("Ulangi PIN baru anda : ");
            scanf("%d", &ulangPin);
            getchar();
            if(baruPin!=ulangPin){
                printf("PIN baru dan ulangi PIN baru harus sama\n");
            }
        }while(baruPin!=ulangPin);
        PIN = baruPin;
        printf("PIN anda sudah diubah\n");
    } else{
        printf("PIN lama yang anda masukkan salah\n");
    }
    
}
int main(){
    char cek;
    int i =0, menu,pin;
    printf("Selamat datang di ATM Smart Money\n");
    do{
        while(i<3){
            printf("\nMasukan PIN anda :");
            scanf("%d", &pin);
            getchar();
            if(PIN == pin){
                printf("=======Selamat datang======");
                printf("\n1. Cek saldo");
                printf("\n2. Tarik tunai");
                printf("\n3. Transfer");   
                printf("\n=========================");
                printf("\nPilih menu : ");
                scanf("%d", &menu);      
                getchar();
                switch (menu){
                case 1:
                    cekSaldo();
                    break;

                case 2:
                    tarikTunai(); 
                    break;

                case 3:
                    transfer();
                    break;

                case 4:
                    ubahPin();
                    break;

                default:
                    printf("Menu tidak ditemukan, harap coba lagi");
                    break;
                }
                printf("\nApakah anda ingin melakukan transaksi lagi? (Y/T) : ");
                scanf("%c", &cek);
                getchar();
                if(cek != 'y' && cek != 'Y'){
                    printf("Transaksi selesai");
                    printf("\nTerima kasih telah menggunakan layanan kami");    
                    return 0;
                } 
                i = 0;
            }else{
                printf("PIN anda salah, coba ulang lagi");
                printf("\nKesempatan ke-%d ", i+1);
                 ;
                // if(i==3){
                //     return 0;
                // }
            }
        }       
        printf("Kesempatan anda habis. \nAkun anda terblokir, silahkan hubungi admin");
    }while(cek == 'y' || cek == 'Y');








    
    return 0;
}