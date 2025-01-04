#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rss.h"

Rss * createEmptyRss() {
  Rss *rss = (Rss*) malloc(sizeof(Rss) * 1);
  rss->title =" ";
  rss->link =" ";
  rss->date =" ";
  rss->description =" ";

  return rss;
}

Rss * createRss(const char * title, const char * link, const char * date, const char * description) {
  Rss *rss = (Rss*) malloc(sizeof(Rss) * 1);
  rss->title = title;
  rss->link = link;
  rss->date = date;
  rss->description = description;
  return rss;
}

void initRss(Rss *feed, const char* title, const char* link, const char* date, const char* description) {
  if(feed==NULL || title==NULL || link==NULL || date==NULL || description==NULL) {
    return;
  }
  feed->title = title;
  feed->link = link;
  feed->date = date;
  feed->description = description;

  return;
}

char *rssToString(const Rss *item) {
  char buffer[1000];
  sprintf(buffer, "%s, %s, %s, %s\n", item->title, item->link, item->date, item->description);
  return NULL;
}

void printRss(const Rss * item) {
  printf("%s, %s, %s, %s\n", item->title, item->link, item->date, item->description);
  return;
}
