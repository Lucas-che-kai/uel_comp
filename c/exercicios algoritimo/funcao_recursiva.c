int busca_esperto_vetor_ordenada(int *V, int q, int i, int f){
    if(i>f){
        return -1;
    }
    if(V[(i+f)/2]==q){
        return (i+f)/2;
    }else if(V[(i+f)/2]>q){
        return busca_esperto_vetor_ordenada(&V, q,  i,  ((i+f)/2)-1 );
    }else {
        return busca_esperto_vetor_ordenada( *V,  q,  ((i+f)/2)+1,  f);
    }
    
}