# Learn Cmake --------------------start------------------------
message("\n--------------------start------------------------")
# 创建一个变量
set(var_name 1234567)
# 打印
message("var : ${var_name}")
message("\n")

# 创建一个列表
set(list_test Python Java CPP Dart)
# 打印
message("list : ${list_test}")
message("\n")

# while循环
set(str "")
while (NOT str STREQUAL "111111")
    set(str "${str}1")
    message("str = ${str}")
endwhile ()
message("\n")

# foreach循环
foreach(item ${list_test})
    message("${item}")
endforeach()
message("\n")

# function
function(func arg1 arg2 arg3)
    message("arg1 = ${arg1}")
    # 参数数量
    message("ARGC = ${ARGC}")
    # 参数列表
    message("ARGV = ${ARGV}")
endfunction(func)

func(1 2 3)


message("--------------------end------------------------\n")
# Learn Cmake --------------------end------------------------
