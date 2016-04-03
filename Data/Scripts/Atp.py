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
	# String with info of the games.

	out_str = ''
	for row in score_reader:
		#idTeam = 0
		if row[7] in teams:
			idTeam = teams[row[7]]
			
		else:
			teams[row[7]] = n_teams
			idTeam = n_teams
			n_teams = n_teams + 1

		if row[17] in teams:
			idTeam2 = teams[row[17]]
		else:
			teams[row[17]] = n_teams
			idTeam2 = n_teams
			n_teams = n_teams + 1

		if n_games == cantFechas:
			break

		n_games = n_games+1
		out_str = out_str + str(n_games) + ' ' + str(idTeam) + ' ' + str(1) + ' ' + str(idTeam2) + ' ' + str(0) + '\n'
	# Write number of teams and games
	outfile.write(str(len(teams)) + ' ' + str(n_games) + '\n')
	# Write games details
	outfile.write(out_str)

