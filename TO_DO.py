




"""
vm = {
	cycle,
	list_processs:
	cycle_last_check :0
	cycle_die
	nbr_live_one_die = 0 // how much op live was declared
	count_max_chek = 0 // count the ckecks for live

}

"""

def exec(vm):
	while(++vm.cycle)
	{
		for prcess in list_processs:
		{

			instruct = vm.arena[prcess.cursors] #### byt 0b => 11 dicml

			if instruct > 0 and instruct < 17:
			{
				if prcess.wait =! -1
					prcess.wait = op_tab[instruct - 1][cycle_wait] ###val wait
				if ( !prcess.wait)
					exec_instruct() ###  add how much jump    curs++=???
				else:
					prcess.wait--
			}
			else:
				prcess.cursors++

		}
		## check if a process declared live cycle_die =>   init=1536
		if (vm.cycle == vm.cycle_last_check + vm.cycle_die OR cycles_to_die <= 0) #all carriages are considered dead :
		{
			vm.cycle_last_check = vm.cycle # always store the last value of process cycle when the last check performed
			vm.count_max_chek++
			check_who_is_alive() ### if process->live == 0: kill else  process->live = 0
			if vm.nbr_live_one_die >= 21 or vm.count_max_chek = 10
			{
				vm.count_max_chek = 0
				vm.nbr_live_one_die = 0
				vm.cycle_to_die -= 50 #CYCLE_DELTA
			}
		}

	}
