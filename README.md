# type_string

type_string inspired by https://blog.therocode.net/2018/09/compile-time-string-parsing

**Known Issue:**
Can not use make_type_string() as template argument directly, like:
```
template<int, make_type_string( "tag" )>
```
compiler report error: a lambda cannot appear in an unevaluated context
