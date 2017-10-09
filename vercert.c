// cc -Wall -O2 -o vercert vercert.c -lcurl
// https://curl.haxx.se/docs/caextract.html

#include <curl/curl.h>
#include <stdio.h>

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.fastmail.com/login/");
        /* url may be redirected, so we tell LibCurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        /* SSL Options */
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1);
        /* Provide CA Certs from http://curl.haxx.se/docs/caextract.html */
        curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* Always cleanup */
        curl_easy_cleanup(curl);
    }

    return 0;
}
