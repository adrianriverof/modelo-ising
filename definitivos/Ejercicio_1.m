

% USO: este código toma "matriz.txt" y devuelve "mapa_colores.png"
% para obtener los distintos mapas del ejercicio 1, hay que ir renombrando
% los archivos de salida.


% Leemos la matriz desde el archivo de texto
nombre_archivo = 'matriz.txt'; 
matriz = readmatrix(nombre_archivo); 

% Creamos una representación gráfica de la matriz
[L, ~] = size(matriz);


figure;

for i = 1:L
    for j = 1:L
        if matriz(i, j) == 1
            % Si el elemento es 1, lo representamos en amarillo
            rectangle('Position', [j-1, L-i, 1, 1], 'FaceColor', [1, 1, 0]);
        elseif matriz(i, j) == -1
            % Si el elemento es -1, lo representamos en negro
            rectangle('Position', [j-1, L-i, 1, 1], 'FaceColor', [0, 0, 0]);
        end
    end
end

% Ajustar la visualización
axis equal;
axis tight;
axis off;


% Guardar la figura en un archivo PNG
saveas(gcf, 'mapa_colores.png');

