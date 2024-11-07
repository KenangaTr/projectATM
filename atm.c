#include <stdio.h>
typedef struct{
    int PIN;
    int norek ;
    long long saldo ;
}ATM;

ATM atm = {1111, 112233, 10000000};

void tarikTunai1(){
int nml= 300000;
    printf("Anda telah menarik tunai sebesar %d", nml);
    atm.saldo -= nml;
    printf("\nSisa saldo anda sebesar %d", atm.saldo);
}

void tarikTunai2(){
int nml= 500000;
    printf("Anda telah menarik tunai sebesar %d", nml);
        atm.saldo -= nml;
    printf("\nSisa saldo anda sebesar %d", atm.saldo);
}

void tarikTunai3(){
int nml= 1000000;
    printf("Anda telah menarik tunai sebesar %d", nml);
        atm.saldo -= nml;
    printf("\nSisa saldo anda sebesar %d", atm.saldo);
}

void tarikTunai4(){
int nml= 2500000;
    printf("Anda telah menarik tunai sebesar %d", nml);
        atm.saldo -= nml;
    printf("\nSisa saldo anda sebesar %d", atm.saldo);
}


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
        if (atm.saldo>=nml){
            if (nml <=1250000){                    
                printf("Anda telah menarik tunai sebesar %d", nml);
                atm.saldo -= nml; nml=0;
                printf("\nSaldo anda sekarang %lld", atm.saldo);
            }else{
                printf("Transfer gagal, nominal transfer melebihi batas maksimal");
            }
        }else{
            printf("Saldo anda tidak cukup");
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

    int i =3, menu,pin, cek;
    printf("Selamat datang di ATM Smart Money\n");
    do {
        do{ 
        printf("\nMasukan PIN anda :");
        scanf("%d", &pin);
        getchar();

        if(atm.PIN == pin){
            // menu menu
                printf("=======Selamat datang======");
                printf("\n1. 300.000,-       5. Cek saldo");
                printf("\n2. 500.000,-       6. Tarik tunai");
                printf("\n3. 1.000.000,-     7. Transfer");
                printf("\n4. 2.500.000,-     8. Ubah PIN");
                printf("\n0. Keluar");
                printf("\n=========================");
                printf("\nPilih menu : ");
                scanf("%d", &menu);      
                getchar();
                switch (menu){
                case 1:
                    tarikTunai1();
                    break;

                case 2:
                    tarikTunai2();
                    break;

                case 3:
                    tarikTunai3();
                    break;

                case 4:
                    tarikTunai4();
                    break;

                case 5:
                    cekSaldo();
                    break;

                case 6:
                    tarikTunai(); 
                    break;

                case 7:
                    transfer();
                    break;

                case 8:
                    ubahPin();
                    break;

                case 0:
                    printf("Terima kasih telah menggunakan layanan kami");
                    return 0;
                    break;

                default:
                    printf("Menu tidak ditemukan, harap coba lagi");
                    break;
                }
                printf("\nApakah anda ingin melakukan transaksi lagi? tekan 1 jika ya : ");
                scanf("%d", &cek);
                getchar();
                if(cek != 1){
                    printf("Transaksi selesai");
                    printf("\nTerima kasih telah menggunakan layanan kami");    
                    return 0;
                } 
        } else {
            printf("PIN anda salah, coba ulang lagi");
            i--;
            printf("\nSisa Kesempatan Anda %d ", i);
        }

        if (i < 1) {
            printf("Kesempatan anda habis. \nAkun anda terblokir, silahkan hubungi admin");
            return 0;
        }
        
        } while(i > 0);
        i = 3;
    } while (cek == 1); 

    
    return 0;
}