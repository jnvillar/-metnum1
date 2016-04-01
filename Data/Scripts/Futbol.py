import csv
import sys
from sets import Set


input_path = sys.argv[1]
output_path = sys.argv[2]

cantFechas = -1
if (len(sys.argv) == 4):
	cantFechas = int(sys.argv[3])

with open(input_path,'rb') as csvfile,open(output_path,'w') as outfile:
	score_reader = csv.reader(csvfile,delimiter=',',skipinitialspace=True)
	# Skip the header
	next(score_reader, None)
	teams = {}
	n_games = 0
	n_teams = 1
	yaLoHice = False
	fecha = 1
	jugadosEstaFecha = 0
	repiteEquipo = False
	# String with info of the games.
	out_str = ''
	for row in score_reader:
		#idTeam = 0
		if row[2] in teams:
			idTeam = teams[row[2]]
			repiteEquipo = True
		else:
			teams[row[2]] = n_teams
			idTeam = n_teams
			n_teams = n_teams + 1

		if row[3] in teams:
			idTeam2 = teams[row[3]]
			repiteEquipo = True	
		else:
			teams[row[3]] = n_teams
			idTeam2 = n_teams
			n_teams = n_teams + 1

		if (repiteEquipo and not yaLoHice):
			yaLoHice = True
			cantPartidosPorFecha = (n_teams+1)/2
			jugadosEstaFecha = 0
			fecha = fecha+1

		if (yaLoHice):
			if jugadosEstaFecha == cantPartidosPorFecha:
				jugadosEstaFecha = 1
				fecha = fecha+1
				if fecha == cantFechas+1:
					break
			else:
				jugadosEstaFecha = jugadosEstaFecha + 1

		
		if row[4] != row[5]:
			out_str = out_str + str(fecha) + ' ' + str(idTeam) + ' ' + row[4] + ' ' + str(idTeam2) + ' ' + row[5] + '\n'
			n_games = n_games+1
	# Write number of teams and games
	outfile.write(str(len(teams)) + ' ' + str(n_games) + '\n')
	# Write games details
	outfile.write(out_str)

