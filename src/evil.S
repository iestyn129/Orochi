.text
.align 2
.global evil
.type evil, %function

evil: // SeqThread* x19, StageRemix* x21
	mov x0, x19
	bl _ZN9SeqThread10pushUnk270Ev
	mov w24, w0

	add x0, x21, x26
	mov x1, x19
	mov w2, #20 // hoop trundling
	bl _Z18sceneChangeInstantPvP9SeqThreadi

	mov x0, x19
	mov w1, w24 // return value of pushUnk270
	bl _ZN9SeqThread15STUB_7100514ff0Ei

.global evil_ret
evil_ret:
    ret

.size evil, .-evil
