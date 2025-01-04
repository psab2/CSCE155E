#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#include "curl_utils.h"

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len + 1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
  size_t new_len = s->len + size * nmemb;
  s->ptr = realloc(s->ptr, new_len + 1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr + s->len, ptr, size * nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size * nmemb;
}

char *getContent(const char *url) {
  char *result = NULL;
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    struct string s;
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "F your user agent tracking BS");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      fprintf(stderr, "cURL encountered an error: %s\n", curl_easy_strerror(res));
    }
    
    result = (char *)malloc(sizeof(char) * (strlen(s.ptr) + 1));
    strcpy(result, s.ptr);
    free(s.ptr);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return result;
}
