pipeline {
    agent any

    stages {
        stage('Clone Repository') {
            steps {
                git branch: 'main', url: 'https://github.com/TheArchitJain/DevOps_Automation.git'
            }
        }

        stage('Build') {
            steps {
                echo 'Building the project...'
                // Add build commands here
            }
        }

        stage('Test') {
            steps {
                echo 'Running tests...'
                // Add test commands here
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying application...'
                // Add deployment commands here
            }
        }
    }
}
