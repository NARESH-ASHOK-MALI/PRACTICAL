cmplx_num operator+(cmplx_num *ptr){
        int sum_real,sum_imag;
        sum_real=0;
        sum_imag=0;
        for (int i = 0; i < 3; i++){
            sum_real+=(ptr+i)->real;
            sum_imag+=(ptr+i)->img;
        }
        cmplx_num xyz;
        xyz.real=this->real+sum_real;
        xyz.img=this->img+sum_imag;
        return xyz;
    }