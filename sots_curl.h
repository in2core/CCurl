#ifndef __SOTS_CURL_H
#define __SOTS_CURL_H

#include <stdbool.h>
#include <curl/curl.h>

typedef size_t (*curl_func)(void *ptr, size_t size, size_t num, void *ud);

// functions for curl_easy_setopt

static CURLcode curl_easy_setopt_string(CURL *curl, CURLoption option, const char *param) {
    return curl_easy_setopt(curl, option, param);
}

static CURLcode curl_easy_setopt_bool(CURL *curl, CURLoption option, bool param) {
    return curl_easy_setopt(curl, option, param);
}

static CURLcode curl_easy_setopt_func(CURL *handle, CURLoption option, curl_func param) {
    return curl_easy_setopt(handle, option, param);
}

static CURLcode curl_easy_setopt_pointer(CURL *handle, CURLoption option, void* param)
{
    return curl_easy_setopt(handle, option, param);
}

static CURLcode curl_easy_setopt_long(CURL *curl, CURLoption option, int64_t param) {
    return curl_easy_setopt(curl, option, param);
}

static CURLcode curl_easy_setopt_slist(CURL *curl, CURLoption option, struct curl_slist *param) {
    return curl_easy_setopt(curl, option, param);
}

// functions for curl_easy_get_info

static CURLcode curl_easy_getinfo_long(CURL *handle, CURLINFO option, int64_t *param) {
    return curl_easy_getinfo(handle, option, param);
}

static CURLcode curl_easy_getinfo_string(CURL *handle, CURLINFO option, const char **param) {
    return curl_easy_getinfo(handle, option, param);
}

static CURLcode curl_easy_getinfo_double(CURL *handle, CURLINFO option, double *param) {
    return curl_easy_getinfo(handle, option, param);
}

static CURLcode curl_easy_getinfo_slist(CURL *handle, CURLINFO option, struct curl_slist **param) {
    return curl_easy_getinfo(handle, option, param);
}

// functions for curl_get_msg_result

static CURLcode curl_get_msg_result(CURLMsg *msg) {
    return msg->data.result;
}

#endif
