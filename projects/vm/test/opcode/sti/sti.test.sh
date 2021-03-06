function test_direct() {
	info "test sti with direct"
	$1 test_direct.cor --dump 100
	info "done"
}

function test_ind() {
	info "test sti with indirect"
	$1 test_ind.cor --dump 100
	info "done"
}

function test_neg() {
	info "test sti with indirect"
	$1 test_neg.cor --dump 525
	info "done"
}

function test_reg() {
	info "test sti with indirect"
	$1 test_reg.cor --dump 525
	info "done"
}

function run() {
	title "\nTest sti opcode\n"
	test_direct $1
	test_ind $1
	test_neg $1
	test_reg $1
}
