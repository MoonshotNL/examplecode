//
//  x509_mod.c
//  
//
//  Created by W.A. Miltenburg on 03-06-13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>


X509 *read_public_certificate()
{
    BIO *tbio = NULL;
    X509 *certificate;
    char *cert = "/usr/local/etc/raddb/certs/server.pem";
    //rlm_testing_t *data;
    
    
    
    tbio = BIO_new_file(cert, "r");
    
    certificate = PEM_read_bio_X509(tbio, NULL, 0, NULL);
	
    
    if(!certificate)
    {
        return NULL;
    }
    
	
    return certificate;
}

X509 *read_private_certificate()
{
    BIO *tbio = NULL;
    X509 *certificate;
    char *cert = "/usr/local/etc/raddb/certs/server.pem";
    char *password;
    //rlm_testing_t *data;
    int size;
    
    //data = (rlm_testing_t *)instance;
    //cert = data->priv_key;
    password = "whatever";
    int password_size = strlen(password);
    
    tbio = BIO_new_file(cert, "r");
    
    certificate = PEM_read_bio_X509(tbio, NULL, NULL, password);
	
    if(!certificate)
    {
        return NULL;
    }
    
	
    return certificate;
}


int main()
{
	read_public_certificate();
	read_private_certificate();
}

