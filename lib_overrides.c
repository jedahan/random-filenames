#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>


#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )

// for caching the original fopen implementation
FILE * (*original_fopen) (const char *, const char *) = NULL;

// our fopen override implmentation
FILE * fopen(const char * filename, const char * mode)
{
    char* adjs[] = { "autumn", "hidden", "bitter", "misty", "silent", "empty", "dry", "dark", "summer", "icy", "delicate", "quiet", "white", "cool", "spring", "winter", "patient", "twilight", "dawn", "crimson", "wispy", "weathered", "blue", "billowing", "broken", "cold", "damp", "falling", "frosty", "green", "long", "late", "lingering", "bold", "little", "morning", "muddy", "old", "red", "rough", "still", "small", "sparkling", "throbbing", "shy", "wandering", "withered", "wild", "black", "young", "holy", "solitary", "fragrant", "aged", "snowy", "proud", "floral", "restless", "divine", "polished", "ancient", "purple", "lively", "nameless" };

    char* nouns[] = { "waterfall", "river", "breeze", "moon", "rain", "wind", "sea", "morning", "snow", "lake", "sunset", "pine", "shadow", "leaf", "dawn", "glitter", "forest", "hill", "cloud", "meadow", "sun", "glade", "bird", "brook", "butterfly", "bush", "dew", "dust", "field", "fire", "flower", "firefly", "feather", "grass", "haze", "mountain", "night", "pond", "darkness", "snowflake", "silence", "sound", "sky", "shape", "surf", "thunder", "violet", "water", "wildflower", "wave", "water", "resonance", "sun", "wood", "dream", "cherry", "tree", "fog", "frost", "voice", "paper", "frog", "smoke", "star" };

    // if we haven’t already, retrieve the original fopen implementation
    if (!original_fopen)
        original_fopen = dlsym(RTLD_NEXT, "fopen");

    // do our own processing; in this case just print the parameters
    printf("== fopen: {%s,%s} ==\n", filename, mode);
    
    char buffer[40];
    char* adj = adjs[rand() % ARR_SIZE(adjs)];
    char* noun = nouns[rand() % ARR_SIZE(nouns)];
    int num = rand() % 9999;
    sprintf(buffer, "%s-%s-%d", adj, noun, num);

    // call the original fopen with the same arugments
    FILE* f = original_fopen(buffer, mode);
    
    // return the result
    return f;
}
