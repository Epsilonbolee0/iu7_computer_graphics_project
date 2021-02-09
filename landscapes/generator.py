def generate_file(size):
    obj_type = "Sphere"
    color = '197 201 199'
    visuals = '100 0.6 0'
    radius = 0.25

    filename = 'test_' + str(size ** 3) + '.lnd'

    with open(filename, 'w') as file:
        print(size ** 3, end = '\n\n', file=file)
    
        for i in range(size):
            for j in range(size):
                for k in range(size):
                    pos = str(i) + ' ' + str(j) + ' ' + str(k)
                    print(obj_type, pos, radius, color, visuals, sep='\n', end='\n\n', file=file)


generate_file(7)  
       
