pipeline {
    agent any

   stage('Clone Repository') {
    steps {
        git branch: 'main', url: 'https://github.com/TheArchitJain/DevOps_Automation.git'
    }
}

        stage('Build') {
            steps {
                echo 'Building the project...'
                // Add your build commands here (e.g., mvn clean install, npm install)
            }
        }
        stage('Test') {
            steps {
                echo 'Running tests...'
                // Add your test commands here (e.g., mvn test, pytest, etc.)
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying application...'
                // Add deployment commands (e.g., docker run, kubectl apply)
            }
        }
    }
}
