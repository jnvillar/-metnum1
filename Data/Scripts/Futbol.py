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
		if row[2] in teams:
			idTeam = teams[row[2]]

		else:
			teams[row[2]] = n_teams
			idTeam = n_teams
			n_teams = n_teams + 1

		if row[3] in teams:
			idTeam2 = teams[row[3]]
		else:
			teams[row[3]] = n_teams
			idTeam2 = n_teams
			n_teams = n_teams + 1
	
		if row[4] != row[5]:
			n_games = n_games+1
			out_str = out_str + str(n_games) + ' ' + str(idTeam) + ' ' + row[4] + ' ' + str(idTeam2) + ' ' + row[5] + '\n'
		
		if n_games == cantFechas:
			break

	# Write number of teams and games
	outfile.write(str(len(teams)) + ' ' + str(n_games) + '\n')
	# Write games details
	outfile.write(out_str)

