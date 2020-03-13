#include <iostream>
#include <string> //untuk to upper
using namespace std;

/* 
RD-Tugas Besar

Reza Octaviany			14117062
*/
void cetak(string input);
void selesai (string input, bool *s);

int main (){
	string input;
	string baru;
	bool cek=false, s=false;
	awal:
        getline (cin,input);
	
	if(input.length()>7){
		if(input[0]=='#' && input[1]==' '){
			input[2]=toupper(input[2]);
			
			if(input[2]=='C'){
				cetak(input);
                cout<<endl;
                goto awal;
			}else if(input[2]=='S'){
				selesai(input, &s);
                if(!s){
                    cout<<"> mohon ketik instruksi dengan benar # cetak atau # selesai"<<endl;
                    goto awal;
                }else{
                    return 0;
                }
			}else{
				cout<<"> pastikan <spasi> setelah tanda pagar # , berjumlah satu\n";
			}
		}else{
			cout<<"> pastikan input diawali tanda pagar\n";
		}
	}else{
		cout<<"> input kan setidaknya 7 huruf\n";
	}
	
	goto awal;
}

void cetak(string input){
	int i;
	string baru,inputan;
	bool kebenaran=false,execute=false;
	
	for(i=0;i<8;i++){
		input[i]=toupper(input[i]);
		baru+=input[i];
	}
	
	if (baru=="# CETAK "){
		while (i<input.length()){
			if(!kebenaran){
				if (input[i]=='"'){
					kebenaran=true;
				}else if(input[i]==' '){
					// do nothing
				}else{
					break;
				}
			}else{
				if (input[i]!='"'){
					inputan+=input[i];
				}else{
					if (input[i+1]!=';'){
						kebenaran = false; break;
					}else{
						i++;
						if(input.length()-1 != i){
							kebenaran=false;
						}else{
							execute=true;
						}
						break;
					}
				}
			}
			
			i++;
		}

		if(!kebenaran){
			cout<<"> pastikan tanda petik berjumlah 2, dan akhiri kalimat dengan titik koma ;";
		}else{
			if (execute){
				cout<<"> "<<inputan;
			}else{
				cout<<"> pastikan tanda petik berjumlah 2";
			}
		}

	}else{
		cout<<"> awali kalimat dengan # cetak dan akhiri dengan titik koma ;";
	}
}

void selesai (string input, bool *s){
    int i;
	string baru,inputan;
	bool kebenaran=false;
	
	for(i=0;i<10;i++){
		input[i]=toupper(input[i]);
		baru+=input[i];
	}
	
	if (baru=="# SELESAI;"){
		cout<<"> Terima kasih sudah menggunakan compiler ini.";
        *s = true;
    }else{
        *s=false;
    }
}
