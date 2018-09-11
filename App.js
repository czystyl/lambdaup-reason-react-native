import React from 'react';
import { StyleSheet, Text, View } from 'react-native';

import { app } from './src/App.bs';

export default class App extends React.Component {
  render() {
    return app();
  }
}
