#include <gtest/gtest.h>

#include "../app/Name.h"

TEST(NameTest, Basic) {
  Name a("A");
  EXPECT_EQ( 42, a.compare((char *)NULL));
  EXPECT_EQ( 0, a.compare((char *)"A"));
  Name b(new Name("BB"));
  EXPECT_EQ( 0, b.compare((char *)"BB"));
  Name c(Name::Multi("A", "B", "C", "D"));
  EXPECT_EQ( 0, c.compare((char *)"A.B.C.D") );
  Name d((const char *)NULL);
  EXPECT_EQ( 42, d.compare((char *)NULL));
  EXPECT_EQ( 42, d.compare((char *)""));
  Name e((Name *)NULL);
  EXPECT_EQ( 42, e.compare((char *)NULL));
  EXPECT_EQ( 42, e.compare((char *)""));
}

class NameTest {
  public:
    NameTest(Name name, int x = 42) {
      _name = name;
      _name.print();
      printf("\n");
    }
    int compare(const char *string) {
      return _name.compare((char *)string);
    }
  private:
    Name _name;
};

TEST(NameTest, Class) {
  NameTest t("cavia", 12);
  EXPECT_EQ( 0, t.compare("cavia"));
  NameTest u(new Name("konijn"));
  EXPECT_EQ( 0, u.compare("konijn"));
  NameTest v(Name::Multi("A", "B", "C"), 45);
  EXPECT_EQ( 0, v.compare("A.B.C"));
  NameTest w(Name::Multi("A", "B", "C", "D"));
  EXPECT_EQ( 0, w.compare("A.B.C.D"));
}

TEST(NameTest, Compare) {
  Name n("eekhoorn");
  Name p("eekhoorn");
  Name q("bever");
  EXPECT_EQ( 42, n.compareName(NULL) );
  EXPECT_EQ( 0, n.compareName(&p) );
  EXPECT_GE( 0, q.compareName(&p) );
  EXPECT_LE( 0, p.compareName(&q) );
  Name g(Name::Multi("Aap","B"));
  Name j(Name::Multi("Aap","A"));
  Name k("Aap");
  Name l("Noot");
  EXPECT_GE( g.compareName(&j), 0 );
  EXPECT_LE( j.compareName(&k), 0 );
  EXPECT_LE( j.compareName(&g), 0 );
  EXPECT_GE( k.compareName(&j), 0 );
  EXPECT_GE( l.compareName(&g), 0 );
  EXPECT_GE( l.compareName(&j), 0 );
  EXPECT_GE( l.compareName(&k), 0 );
}

TEST(NameTest, Shortcut) {
  char line[100];

  Name g(Name::Multi("Aap","B"));
  g.snprint(line);
  EXPECT_EQ( 0, strcmp(line, "Aap.B") );

  Name p("eekhoorn");
  p.snprint(line);
  EXPECT_EQ( 0, strcmp(line, "eekhoorn") );
}
