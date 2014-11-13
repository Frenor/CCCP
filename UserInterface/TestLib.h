#ifndef TESTLIB_H
#define TESTLIB_H

#if defined TEST_EXPORT_LIB
#define TEST_LIB  Q_DECL_EXPORT
#else
#define TEST_LIB Q_DECL_IMPORT
#endif
#endif //TESTLIB_H