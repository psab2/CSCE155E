#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "curl_utils.h"
#include "rss_utils.h"
#include "rss.h"

/**
 * Main driver program for the RSS feed demo.  You can provide
 * command line arguments 1 - 3 to connect to different feeds.
 */
int main(int argc, char **argv) {
  // default: School of Computing News
  RssService s = cseBitsAndBytes;

  if (argc > 1) {
    int choice = atoi(argv[1]);
    if (choice == 2) {
      s = unlNews;
    } else if (choice == 3) {
      s = reddit;
    } else if (choice == 4) {
      s = pintrest;
    }
  }

  printf("Using RSS Service: %s (%s)\n", s.name, s.url);

  char *rawXml = getContent(s.url);

  xmlDocPtr doc = xmlReadMemory(rawXml, strlen(rawXml), "noname.xml", NULL, 0);
  xmlNode *rootElement = xmlDocGetRootElement(doc);

  if (s.type == RSS2) {
    parseRssXml(rootElement);
  } else if (s.type == ATOM1) {
    parseAtomXml(rootElement);
  } else {
    fprintf(stderr, "Undefined Service Type: %d\n", s.type);
  }

  xmlCleanupParser();
  return 0;
}
