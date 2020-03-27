	shift_sp 1
	push_const EXIT
	push_reg fp
	push_reg sp
	pop_reg fp
	jump main
EXIT:
	exit
func:
	push_reg fp
	push_const 2
	add
	push_const 2
	add
	push_const 1
	add
	push_const 3
	push_const 1
	mul
	add
	fetch
	write_int
str_0. string "\n"
	push_const str_0
	write_string
	push_reg fp
	push_const 2
	add
	push_const 2
	add
	push_const 0
	add
	fetch
	write_int
str_1. string "\n"
	push_const str_1
	write_string
	push_reg fp
	push_const 2
	add
	push_const 0
	add
	fetch
	write_int
str_2. string "\n"
	push_const str_2
	write_string
	push_reg fp
	push_const -2
	add
	push_reg fp
	push_const 2
	add
	assign
func_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
func_end:
func2:
	shift_sp 8
func2_start:
	push_reg fp
	push_const 1
	add
	push_const 0
	add
	push_reg sp
	fetch
	push_const 5
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 1
	add
	push_const 2
	add
	push_const 0
	add
	push_reg sp
	fetch
	push_const 44
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 1
	add
	push_const 2
	add
	push_const 1
	add
	push_const 3
	push_const 1
	mul
	add
	push_reg sp
	fetch
	push_const 333
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const -2
	add
	push_reg fp
	push_const 1
	add
	assign
func2_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
func2_end:
main:
	shift_sp 31
main_start:
	push_reg fp
	push_const 3
	add
	push_reg sp
	fetch
	push_const 11111
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 1
	add
	push_reg sp
	fetch
	push_const 99999
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 8
	add
	push_const 0
	add
	push_reg sp
	fetch
	push_const 9
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 8
	add
	push_const 2
	add
	push_const 0
	add
	push_reg sp
	fetch
	push_const 88
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 8
	add
	push_const 2
	add
	push_const 1
	add
	push_const 3
	push_const 1
	mul
	add
	push_reg sp
	fetch
	push_const 777
	push_const -1
	mul
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 16
	add
	shift_sp 1
	push_const label_1
	push_reg fp
	push_const 2222
	push_const -1
	mul
	push_reg fp
	push_const 8
	add
	push_reg sp
	push_const -0
	add
	fetch
	push_const 1
	add
	fetch
	push_reg sp
	push_const -1
	add
	fetch
	push_const 2
	add
	fetch
	push_reg sp
	push_const -2
	add
	fetch
	push_const 3
	add
	fetch
	push_reg sp
	push_const -3
	add
	fetch
	push_const 4
	add
	fetch
	push_reg sp
	push_const -4
	add
	fetch
	push_const 5
	add
	fetch
	push_reg sp
	push_const -5
	add
	fetch
	push_const 6
	add
	fetch
	push_reg sp
	push_const -6
	add
	fetch
	push_const 7
	add
	fetch
	shift_sp -7
	fetch
	shift_sp 7
	push_reg fp
	push_const 1
	add
	fetch
	push_reg sp
	push_const -10
	add
	pop_reg fp
	jump func
label_1:
	push_reg sp
	push_const -1
	add
	fetch
	push_const 0
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 0
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 1
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 1
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 2
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 2
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 3
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 3
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 4
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 4
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 5
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 5
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 6
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 6
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 7
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 7
	add
	fetch
	assign
	shift_sp -2
	push_reg fp
	push_const 24
	add
	push_reg fp
	push_const 8
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 0
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 0
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 1
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 1
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 2
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 2
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 3
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 3
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 4
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 4
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 5
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 5
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 6
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 6
	add
	fetch
	assign
	push_reg sp
	push_const -1
	add
	fetch
	push_const 7
	add
	push_reg sp
	push_const -1
	add
	fetch
	push_const 7
	add
	fetch
	assign
	shift_sp -2
	push_reg fp
	push_const 16
	add
	push_const 2
	add
	push_const 1
	add
	push_const 3
	push_const 1
	mul
	add
	fetch
	write_int
str_3. string "\n"
	push_const str_3
	write_string
	push_reg fp
	push_const 16
	add
	push_const 2
	add
	push_const 0
	add
	fetch
	write_int
str_4. string "\n"
	push_const str_4
	write_string
	push_reg fp
	push_const 16
	add
	push_const 0
	add
	fetch
	write_int
str_5. string "\n"
	push_const str_5
	write_string
	push_reg fp
	push_const 24
	add
	push_const 2
	add
	push_const 1
	add
	push_const 3
	push_const 1
	mul
	add
	fetch
	write_int
str_6. string "\n"
	push_const str_6
	write_string
	push_reg fp
	push_const 24
	add
	push_const 2
	add
	push_const 0
	add
	fetch
	write_int
str_7. string "\n"
	push_const str_7
	write_string
	push_reg fp
	push_const 24
	add
	push_const 0
	add
	fetch
	write_int
str_8. string "\n"
	push_const str_8
	write_string
	push_reg fp
	push_const 6
	add
	push_reg sp
	fetch
	shift_sp 1
	push_const label_2
	push_reg fp
	push_const 2222
	push_const -1
	mul
	push_reg fp
	push_const 8
	add
	push_reg sp
	push_const -0
	add
	fetch
	push_const 1
	add
	fetch
	push_reg sp
	push_const -1
	add
	fetch
	push_const 2
	add
	fetch
	push_reg sp
	push_const -2
	add
	fetch
	push_const 3
	add
	fetch
	push_reg sp
	push_const -3
	add
	fetch
	push_const 4
	add
	fetch
	push_reg sp
	push_const -4
	add
	fetch
	push_const 5
	add
	fetch
	push_reg sp
	push_const -5
	add
	fetch
	push_const 6
	add
	fetch
	push_reg sp
	push_const -6
	add
	fetch
	push_const 7
	add
	fetch
	shift_sp -7
	fetch
	shift_sp 7
	push_reg fp
	push_const 1
	add
	fetch
	push_reg sp
	push_const -10
	add
	pop_reg fp
	jump func
label_2:
	push_const 2
	add
	push_const 0
	add
	fetch
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 6
	add
	fetch
	write_int
str_9. string "\n"
	push_const str_9
	write_string
	push_reg fp
	push_const 6
	add
	push_reg sp
	fetch
	shift_sp 1
	push_const label_3
	push_reg fp
	push_reg sp
	pop_reg fp
	jump func2
label_3:
	push_const 2
	add
	push_const 0
	add
	fetch
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 6
	add
	fetch
	write_int
str_10. string "\n"
	push_const str_10
	write_string
	push_reg fp
	push_const 6
	add
	push_reg sp
	fetch
	shift_sp 1
	push_const label_4
	push_reg fp
	push_reg sp
	pop_reg fp
	jump func2
label_4:
	push_const 2
	add
	push_const 1
	add
	push_const 3
	push_const 1
	mul
	add
	fetch
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 6
	add
	fetch
	write_int
str_11. string "\n"
	push_const str_11
	write_string
	push_reg fp
	push_const 6
	add
	push_reg sp
	fetch
	shift_sp 1
	push_const label_5
	push_reg fp
	push_reg sp
	pop_reg fp
	jump func2
label_5:
	push_const 0
	add
	fetch
	assign
	fetch
	shift_sp -1
	push_reg fp
	push_const 6
	add
	fetch
	write_int
str_12. string "\n"
	push_const str_12
	write_string
	push_reg fp
	push_const -2
	add
	push_const 0
	assign
main_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
main_end:
Lglob.	data 10
