#include <stdio.h>
typedef struct{
    int PIN;
    int norek ;
    long long saldo ;
}ATM;

ATM atm = {1111, 112233, 10000000};

void cekSaldo(){
    printf("Saldo anda : %lld", atm.saldo);
}
   
void tarik50(){
    int nml, menu;
    printf("Batas maksimal penarikan : Rp. 1.250.000 \n");
    printf("Masukan nominal :");
    scanf("%d", &nml);
    getchar();
    if (nml%50000==0){
        if (nml <=2500000){                    
            printf("Anda telah menarik tunai sebesar %d", nml);
            atm.saldo -= nml; nml=0;
            printf("\nSaldo anda sekarang %lld", atm.saldo);
        }else{
            printf("Transfer gagal, nominal transfer melebihi batas maksimal");
        }
    }else{
        printf("Nominal harus kelipatan 50.000\n");
    }
    
}

void tarik100(){
    int nml, menu;
    printf("Batas maksimal penarikan : Rp. 2.500.000 \n");
    printf("Masukan nominal :");
    scanf("%d", &nml);
    getchar();
    if (nml%100000==0){
        if (nml <=2500000){                    
            printf("Anda telah menarik tunai sebesar %d", nml);
            atm.saldo -= nml; nml=0;
            printf("\nSaldo anda sekarang %lld", atm.saldo);
        }else{
            printf("Transfer gagal, nominal transfer melebihi batas maksimal");
        }
    }else{
        printf("Nominal harus kelipatan 100.000\n");
    }
}
void tarikTunai(){
    int menu;
    printf("Pilih Penarikan");
    printf("\n1. 50.000");
    printf("\n2. 100.000");  
    printf("\n=========================");
    printf("\nPilih menu : ");
    scanf("%d", &menu);      
    getchar();
    
    switch (menu){
    case 1:
        tarik50();
        break;
    case 2:
        tarik100();
        break;
    
    default:
        printf("tidak ada menu");
        break;
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
    if(atm.norek == tf){
        printf("Transfer gagal, nomor rekening tujuan sama dengan rekening anda");
    } else if(nml <= atm.saldo){
        atm.saldo -= nml; nml=0;
        printf("Transfer berhasil, saldo anda sekarang %lld", atm.saldo);
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
    if(lamaPin == atm.PIN){
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
        atm.PIN = baruPin;
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
            if(atm.PIN == pin){
                printf("=======Selamat datang======");
                printf("\n1. Cek saldo");
                printf("\n2. Tarik tunai");
                printf("\n3. Transfer");   
                printf("\n4. Ubah PIN");   
                printf("\n5. Keluar");   
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

                case 5:
                    printf("Terima kasih telah menggunakan layanan kami");
                    return 0;
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
                i++;
            }
        }       
        printf("Kesempatan anda habis. \nAkun anda terblokir, silahkan hubungi admin");
    }while(cek == 'y' || cek == 'Y');








    
    return 0;
}