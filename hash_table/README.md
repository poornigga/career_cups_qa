
CAREER_CAP
==========

## hash table



node {

    key_hash;

    key_len;

    value:[key + value];

}


list [  node - node - node ]


bucket [ list - list - list ]


table {

    size;

    bucket;

    func:len(key)%size;

    func2:len(key);

}



## test
    
    make clean; make
