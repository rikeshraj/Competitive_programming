/ 761. Special Binary String
int compare(const void *a, const void *b) {
    return strcmp(*(char **)b, *(char **)a);
} 
char* makeLargestSpecial(char* s) {
    int len = strlen(s); 
    if(len == 0) return strdup("");
    int count = 0, i = 0, num_spec = 0; 
    char** spec = malloc(len * sizeof(char*));
    for(int j=0; j<len; j++) {
        count += (s[j] == '1') ? 1 : -1;
        if(count == 0) {
            int sub_len = j-i-1;
            char* inner = malloc(sub_len + 1);
            strncpy(inner, s+i+1, sub_len);
            inner[sub_len] = '\0';
            char* processed_inner = makeLargestSpecial(inner);
            spec[num_spec] = malloc(strlen(processed_inner) + 3);
            sprintf(spec[num_spec], "1%s0", processed_inner);
            num_spec++;
            i = j+1; 
            free(inner);
            free(processed_inner);
        }
    }
    qsort(spec, num_spec, sizeof(char*), compare);
    char* result = calloc(len+1, 1);
    for(int k=0; k<num_spec; k++) {
        strcat(result, spec[k]);
        free(spec[k]);
    }
    free(spec);
    return result; 
}
