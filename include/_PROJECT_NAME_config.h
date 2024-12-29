#ifndef __<PROJECT_NAME>_CONFIG_H__
#define __<PROJECT_NAME>_CONFIG_H__

#ifdef _MSC_VER
#define REGION(x) _Pragma("region " #x)
#define END_REGION _Pragma("endregion")
#else
#define REGION(x)
#define END_REGION
#endif

#if __cpp_concepts >= 201907
#define REQUIRES(x) requires x
#define CONSTRAINT(x) x
#else
#define REQUIRES(x)
#define CONSTRAINT(x) typename
#endif // __cpp_concepts (lower part)

//Using EXPORT and LOCAL instead of EXPORT and NO_EXPORT to 
//Make it harder to mistakenly type export when you don't mean to.

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef <PROJECT_NAME>_BUILD_DLL
#define <PROJECT_NAME>_EXPORT __declspec(dllexport)
//#define <PROJECT_NAME>_EXPORT_TEMPLATE // Will this cause issues in other dll's?
#else
#define <PROJECT_NAME>_EXPORT __declspec(dllimport) 
//#define <PROJECT_NAME>_EXPORT_TEMPLATE extern //Will this cause issues in other dll's?
#endif
#define <PROJECT_NAME>_LOCAL
#else
#ifndef __has_attribute
#define __has_attribute(x) 0  // Compatibility with non-clang compilers.
#endif

#if (defined(__GNUC__) && (__GNUC__ >= 4)) ||\
      (defined(__clang__) && __has_attribute(visibility))

#define <PROJECT_NAME>_EXPORT __attribute__ ((visibility ("default")))
#define <PROJECT_NAME>_LOCAL  __attribute__ ((visibility ("hidden")))
//#define <PROJECT_NAME>_EXPORT_TEMPLATE  // Will this cause issues in other dll's?
#else
#define <PROJECT_NAME>_EXPORT
#define <PROJECT_NAME>_LOCAL
//#define <PROJECT_NAME>_EXPORT_TEMPLATE  // Will this cause issues in other dll's?
#endif
#endif


#endif
